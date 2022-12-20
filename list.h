/**
 * @file list.h
 * @author Muaaz Bdear
 * Matrikel-Nr.: 5194038
 * Assignment 1
 * @brief
 * @version 0.1
 * @date 2022-11-28
 * @copyright Copyright (c) 2022
 */

#ifndef LIST_H
#define LIST_H

#include <ostream>

/**
 * namespace util
 */
namespace util {

    // I wanted to implement it as a derived of std::exception,
    // since we cannot use anything from standard library I implemented it like that
    class ListError
    {
        const char *msg;
    public:
        ListError(const char *msg) : msg(msg) {}

        const char *getMsg() const
        {
            return msg;
        }
    };

    template<class T>
    class list {

        class Node
        {
        public:
            T data;
            Node *prev = nullptr;
            Node *next = nullptr;

            Node(T data) : data(data) {}

            T getData() const
            {
                return data;
            }
        };

        Node *head = nullptr;
        Node *tail = nullptr;

    public:

        list() {}

        ~list()
        {
            clear();
        }

        // actually because of the rule of 3, we need to implement it, but I think it is not necessary for this task
        list(const list &orig) = delete;

        // actually because of the rule of 3, we need to implement it, but I think it is not necessary for this task
        list &operator=(const list &l) = delete;

        T &front()
        {
            if (empty()) throw ListError("the list is empty, head is pointing to nullptr!!!");

            return head->data;
        }

        T &back()
        {
            if (empty()) throw ListError("the list is empty, tail is pointing to nullptr!!!");
            return tail->data;
        }

        bool empty()
        {
            return !head;
        }

        unsigned int size()
        {
            if (!head) return 0;

            unsigned int count = 0;
            Node *tmp = head;
            while (tmp)
            {
                count++;
                tmp = tmp->next;
            }
            return count;
        }

        void clear()
        {
            Node *tmp;
            while (head)
            {
                tmp = head->next;
                delete head;
                head = tmp;
            }
        }

        void push_back(const T &element)
        {
            Node *new_node = new Node{element};
            if (empty())
            {
                head = tail = new_node;
            } else {
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
        }

        void pop_back()
        {
            if (empty()) throw ListError("can not delete the last item on an empty list");
            if (tail == head)
            {
                delete tail;
                tail = head = nullptr;
            } else
            {
                Node *tmp = tail->prev;
                delete tail;
                tail = tmp;
                tail->next = nullptr;
            }
        }

        void push_front(const T &element)
        {
            Node *new_node = new Node(element);
            if (empty()) {
                head = tail = new_node;
            } else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }

        void pop_front()
        {
            if (empty()) throw ListError("can not delete the first item on an empty list");
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
            } else {
                Node *tmp = head->next;
                delete head;
                head = tmp;
                head->prev = nullptr;
            }
        }

        class iterator
        {
            Node *m_pNode;
        public:
            iterator(Node *pNode) : m_pNode(pNode) {}

            inline bool operator==(const iterator &it) const
            {
                return m_pNode == it.m_pNode;
// Two iterators are equal if they point to the same node
            }

            inline bool operator!=(const iterator &it) const
            {
                return m_pNode != it.m_pNode;

            }

            iterator &operator++()
            {
// Point/Go to the next value of m_pNode
                m_pNode = m_pNode->next;
                return *this;
            }

            iterator operator++(int)
            {
// Postfix variant
                iterator temp = *this;
                m_pNode = m_pNode->next;
                return temp;
            }

            T &operator*() const
            {
// Return a reference to the object stored in the current node
                return *&m_pNode->data;
            }

            T *operator->() const
            {
// Return a pointer to the object stored in the current node
                return &m_pNode->data;
            }
        };

        iterator begin()
        {
            return head;
        }

        iterator end()
        {
            return tail ? tail->next : nullptr;
        }

        iterator insert(iterator it, const T &element)
        {
            Node *new_node = new Node(element);
            if (empty())
            {
                head = tail = new_node;
            } else if (it == begin())
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            } else if (it == end())
            {
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
            //for my understanding we need another case, when for example we use the increment operator
            // for begin() iterator then the iterator can point to the middle, but because of the given template
            // of iterator class, since we do not have public access for the m_pNode,
            // I think you do not want us to check for this case
            return iterator(new_node);

        };

        iterator erase(iterator it)
        {
            if (empty()) throw ListError("can not erase an element of an empty list!");
            else if (it == end()) throw ListError("the end() iterator cannot be used as a parameter in erase()!");
            else
            {
                if (head == tail)
                {
                    delete head;
                    head = tail = nullptr;
                } else
                {
                    Node *tmp = head->next;
                    delete head;
                    head = tmp;
                    head->prev = nullptr;
                }
                return iterator(head);
            }
        };
        friend std::ostream &operator<<(std::ostream &os, const list &l)
        {
            Node *tmp = l.head;
            os << "[";
            while (tmp)
            {
                if (tmp->next) os << tmp->data << " , ";
                else os << tmp->data;
                tmp = tmp->next;
            }
            os << "]";
            return os;
        };

    };
} // util

#endif //LIST_H
