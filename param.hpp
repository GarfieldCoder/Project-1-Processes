#ifndef PARAM_H
#define PARAM_H

#define MAXARGS 32 // don't test more than this many args

class Param {
	private:
		char *inputRedirect; /* file name or NULL */
		char *outputRedirect; /* file name or NULL */
		int background; /* either 0 (false) or 1 (true) */
		int argumentCount; /* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; /* array of strings */
	public:
		Param();
		Param(int argc, char* argv[]);
		void printParams() const;
};

#endif