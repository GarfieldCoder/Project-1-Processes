#ifndef PARAM_HPP
#define PARAM_HPP

// The handout states that no test input will contain more than MAXARGS tokens.
#define MAXARGS 32

class Param {
private:
    char *inputRedirect;
    char *outputRedirect;
    int background;
    int argumentCount;
    char *argumentVector[MAXARGS];

public:
    Param();
    ~Param();

    void printParams() const;
};

#endif
