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

    // Clear data from the previous command before parsing a new one.
    void reset();
    void setInputRedirect(const char *filename);
    void setOutputRedirect(const char *filename);
    void setBackground(int value);
    void addArgument(const char *argument);

    void printParams() const;
};

#endif
