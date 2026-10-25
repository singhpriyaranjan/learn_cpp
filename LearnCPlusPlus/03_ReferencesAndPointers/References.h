#ifndef CPP_LEARNING_REFERENCES_H
#define CPP_LEARNING_REFERENCES_H

class ReferencesExample
{
public:
    void run();

private:
    void addBonus(int& score) const;
};

#endif