/*
** EPITECH PROJECT, 2018
** sldkfj
** File description:
** sdlkfj
*/

#ifndef NUMBER_H_
	#define NUMBER_H_

//#define CHECK_NUM(a, b, ...) check_number(a, b, (defaultNumber, ##__VA_ARGS__))

typedef enum {
    SGT_NONE = 1,
    SGT_ALLOW_NEGATIVE = 2,
    SGT_STRICT_NEGATIVE = 4,
    SGT_ALLOW_DECIMAL = 8,
    SGT_NON_NULL = 16,
    SGT_RANGE_UP_INCLUDED = 32,
    SGT_RANGE_DOWN_INCLUDED = 64,
    SGT_RANGE = 128,
    SGT_MODULO = 256,
}  number_opts_t;

typedef struct {
    double range_down;
    double range_up;

    double modulo;
} customNumber_t;

#endif /* !NUMBER_H_ */
