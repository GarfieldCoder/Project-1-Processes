#ifndef PARAM_H
#define PARAM_H

#define MAXARGS 32 // don't test more than this many args or the computer will explode!

class Param {
	private:
		char *inputRedirect; /* file name or NULL */
		char *outputRedirect; /* file name or NULL */
		int background; /* either 0 (false) or 1 (true) */
		int argumentCount; /* number of tokens in argument vector */
		/* One extra entry is reserved for the NULL pointer required by exec(). */
		char *argumentVector[MAXARGS + 1]; /* array of strings */

	public:
		Param();
		Param(int argc, char* argv[]);
		~Param();
		void reset();
		void setInputRedirect(const char *filename);
		void setOutputRedirect(const char *filename);
		void setBackground(int value);
		void addArgument(const char *argument);
		const char *getInputRedirect() const;
		const char *getOutputRedirect() const;
		int getBackground() const;
		int getArgumentCount() const;
		char *const *getArgumentVector() const;
		void printParams() const;
};

#endif
