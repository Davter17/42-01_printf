#!/bin/bash

cd "$(dirname "$0")/.."

FAIL=0
UTILS="test/test_utils.c"
LIBFT_INC=".deps/libft/inc"

for test_src in test/test_*.c; do
	name=$(basename "$test_src" .c)
	if [ "$name" = "test_utils" ]; then
		continue
	fi
	cc -Wall -Wextra -Werror -Iinc -I"$LIBFT_INC" -Itest "$UTILS" "$test_src" \
		-L. -lftprintf -o "test/$name"
	if [ $? -ne 0 ]; then
		printf "\033[31mCOMPILE FAIL: %s\033[0m\n" "$name"
		FAIL=$((FAIL + 1))
		continue
	fi
	./"test/$name"
	ret=$?
	if [ $ret -ne 0 ]; then
		FAIL=$((FAIL + ret))
	fi
done

rm -f test/test_percent test/test_char test/test_str test/test_int
rm -f test/test_unsigned test/test_hex test/test_ptr test/test_misc

echo ""
if [ $FAIL -eq 0 ]; then
	printf "\033[1;32m  ALL TESTS PASSED!\033[0m\n"
else
	printf "\033[1;31m  SOME TESTS FAILED!\033[0m\n"
fi
echo ""
exit $FAIL
