#pragma once

class RetweetCollection
{
public:
    RetweetCollection() : size_(0) {}
    bool isEmpty() const
    {
        return 0 == size();
    }
    size_t size() const
    {
        return isEmpty() ? 0 : 1;
    }
    void add(const Tweet &tweet) {
        size_ = 1;
    }

private:
    size_t size_;
};