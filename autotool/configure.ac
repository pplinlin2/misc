AC_INIT([amhello], [1.0], [bug-report@address])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

dnl
dnl AC_PATH_PROG(variable, prog-to-check-for, [value-if-not-found], [path = '$PATH'])
dnl AC_DEFINE_UNQUOTED(variable, value, [description])
dnl
AC_PATH_PROG([EXEC], [exec.sh], /tmp/exec.sh, [.])
AC_DEFINE_UNQUOTED([EXEC], "$EXEC", [path to exec.sh])

AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
