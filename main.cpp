/* Global includes */
#include <assert.h>
#include <stddef.h>
#include <new>

/* Local includes */
#include "PongApplication.hpp"
#include "CRconstants.hpp"

int main(int argc, char** argv){

	// Default the exit code
	int exitCode = crp::STATUS_NO_ERROR;

	// Create instance of pong application
	crp::Application * pongGame = new(std::nothrow) crp::Application();
	assert(NULL != pongGame && "main() can't create Application");

	// Run application
	exitCode = pongGame->run();

	// Cleanup by deleting application instance
	delete pongGame;

	// Remove pointers to objects created in application instance
	pongGame = NULL;

	// Return exit code, duh!
	return exitCode;
}