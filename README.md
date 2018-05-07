# Surgitoir - Argument parsing library by Ratouney


### bool_t check_number(char *your_argument, opt_t binary_mask, customNumber_t *param)

1. Your argument

    Just gimme a goddam string, (null terminated, else go F*** yourself).

2. Possible values for the binary options : 

    | Code | Effect |
    |---|---|
    | SGT_ANY  | Positive integer only  |
    | SGT_ALLOW_NEGATIVE | Allow negative values |
    | SGT_STRICT_NEGATIVE| Only accept negative values |
    | SGT_NON_NULL | Discard null values |
    | SGT_RANGE | Use the range values in the param struct |
    | SGT_RANGE_UP_INCLUDED | Include the upper value (<= x) |
    | SGT_RANGE_DOWN_INCLUDED | Include the lower value (>= x) |
    | SGT_MODULO | Use the modulo value in the param struct |

3. The param struct is defined as follows

        customNumber_t {
            double range_down; // defaulted to 0.0
            double range_up; // defaulted to 1.0

            double modulo; // defaulted to 1.0
        }

    You can pass `NULL` if you don't need any of those

___

### throw_err(SGT_TRUE || SGT_FALSE)

1. Crash or not ?

    If the previous function returned an error, it will be stored in the following variable :

    > extern error_t *sgt_error;

    If called, the `throw_err(SGT_TRUE)` macro will display the string and the error that occured.

    ```
        INPUT: 4.2.6

        OUTPUT : [4.2.6] --> MULTIPLE_FLOATING_POINTS

    ```

    It will then exit with the current exit code (by default 84). (it can be changed with `set_exit_code(int)`)
    

___
### set_exit_code(int code)

1. Not so secret

    If any errors occurs and the THROW_ERR macro is called, the program will exit with this code.