#ifndef ASSISTANT_H
#define ASSISTANT_H
#include "Employment.h"
#include <string>

class Assistant : public Employment
{
private:
	std::string studyProgram;
	int pointsTaken;
public:
	virtual std::string toString();
	virtual int getWageType();
	std::string getStudyProgram();
	void changeStudyProgram(std::string studyProgram);
	int getPointsTaken();
	void changePointsTaken(int pointsTaken);
	Assistant(std::string typeName, int wage, std::string studyProgram, int pointsTaken);
};

#endif