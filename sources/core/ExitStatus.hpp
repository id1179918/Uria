/*
-
  -
    -
  -
-
Uria - 2024

Thomas ROUSTAN
-
  -
    -
  -
-
*/

#ifndef EXIT_STATUS_HPP
#define EXIT_STATUS_HPP

#define EX_OK                   1      /* successful termination */
#define EX_ESCAPE               2      /* closing application  */
#define EX_INTERRUPT            3      /* interrupting application (e.g., ctrl+c) */
#define EX_FAIL_OPEN_INPUT      4      /* cannot open input */
#define EX_OSERR                5      /* system error (e.g., can't fork) */

#define EX_NCURSES    100

#endif