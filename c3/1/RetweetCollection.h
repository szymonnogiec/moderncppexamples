#pragma once

class RetweetCollection
{
public:
    RetweetCollection() :
        empty_(true) {}

    bool isEmpty() const
    {
        return empty_;
    }
    void add(const Tweet &tweet)
    {
        empty_ = false;
    }

    void remove(const Tweet &tweet)
    {
        empty_ = true;
    }

    size_t size() const
    {
        return isEmpty() ? 0 : 1;
    }

private:
    bool empty_;
};