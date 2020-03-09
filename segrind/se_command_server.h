//
// Created by derrick on 3/8/20.
//

#ifndef SE_VALGRIND_SE_COMMAND_SERVER_H
#define SE_VALGRIND_SE_COMMAND_SERVER_H

#include "se.h"
#include "se_command.h"

typedef enum se_server_state {
  SERVER_INVALID,            /* Error State */
  SERVER_WAIT_FOR_START,     /* Server is initialized and ready to start */
  SERVER_START,              /* Server is starting */
  SERVER_WAIT_FOR_TARGET,    /* Server is waiting for a target function */
  SERVER_WAIT_FOR_CMD,       /* Server is waiting for a command */
  SERVER_FUZZING,            /* Server is fuzzing program state */
  SERVER_EXECUTING,          /* Server is executing target function */
  SERVER_EXIT,               /* Server is exiting */
  SERVER_REPORT_ERROR,       /* Server reported an error */
  SERVER_SETTING_CTX,        /* Server is establishing input program state */
  SERVER_WAITING_TO_EXECUTE, /* Server is ready to execute target function */
} SE_(cmd_server_state);

typedef struct {
  SE_(cmd_server_state) current_state;
  Int commander_r_fd, commander_w_fd;
} SE_(cmd_server);

/**
 * @brief Initializes and returns a command server
 * @param commander_r_fd - Path to commander read pipe
 * @param commander_w_fd - Path to commander write pipe
 * @return command server or -1 on failure
 */
SE_(cmd_server) * SE_(make_server)(const HChar *commander_in_path,
                                   const HChar *commander_out_path);

/**
 * @brief Starts listening for commands
 * @param server
 */
void SE_(start_server)(SE_(cmd_server) * server);

/**
 * @brief Determines if the server can transition to next_state from its current
 * state
 * @param server
 * @param next_state
 * @return True if next_state is a valid transition
 */
Bool SE_(is_valid_transition)(const SE_(cmd_server) * server,
                              SE_(cmd_server_state) next_state);

/**
 * @brief Checks for correct transition and sets the server state if correct
 * @param server
 * @param next_state
 * @return True if new state is set
 */
Bool SE_(set_server_state)(SE_(cmd_server) * server,
                           SE_(cmd_server_state) next_state);

/**
 * @brief Checks if the message is actionable given the current state of the
 * server
 * @param server
 * @param msg
 * @return True if the message can be acted upon
 */
Bool SE_(msg_can_be_handled)(const SE_(cmd_server) * server,
                             const SE_(cmd_msg) * msg);

const HChar *SE_(server_state_str)(SE_(cmd_server_state) state);

#endif // SE_VALGRIND_SE_COMMAND_SERVER_H