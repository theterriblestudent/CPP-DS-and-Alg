#ifndef LINEARLIST_H
#define LINEARLIST_H

template<class T>
class LinearList {
    public:
        virtual ~LinearList() = default;
        virtual bool isEmpty() const = 0;
        virtual void prepend(const T&) = 0;
        virtual void append(const T&) = 0;
        virtual int size() const = 0;
        virtual int indexOf(const T&) const = 0;
        virtual void remove(int) = 0;
        virtual void insert(const T&, int) = 0;
};
#endif // #ifndef LINEARLIST_H