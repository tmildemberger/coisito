#ifndef THING_HPP
#define THING_HPP

class Thing {
public:
    Thing(int val);
    virtual ~Thing() = default;

    int getVal() const;

protected:
    int val_;
};

#endif // THING_HPP