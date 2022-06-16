#pragma once

class Binder {
public:
    void clear();
};

class TriangleFilterBase {
public:
    TriangleFilterBase(TriangleFunc function) {
        mFunction = function;
    }

    virtual bool isInvalidTriangle(const Triangle *) const = 0;

    TriangleFunc mFunction; // _4
};

class TriangleFilterFunc : public TriangleFilterBase {
public:
    virtual bool isInvalidTriangle(const Triangle *) const;
};