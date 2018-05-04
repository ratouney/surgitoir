# Surgitoir
## Argument parsing library by Ratouney


### CHECKNUM(char *your_argument, opt_t binairy_mask, [customNumber_t param])

> Your argument

    Just gimme a goddam string, (null terminated, else go F*** yourself).

> Possible values for the binairy options : 

| Code | Effect |
|---|---|
| SGT_NONE  | Positive integer only  |
| SGT_ALLOW_NEGATIVE | Allow negative values |
| SGT_STRICT_NEGATIVE| Only accept negative values |
| SGT_NON_NULL | Discard null values |
| SGT_RANGE | Use the range values in the param struct |
| SGT_RANGE_UP_INCLUDED | Include the upper value (<= x) |
| SGT_RANGE_DOWN_INCLUDED | Include the lower value (>= x) |
| SGT_MODULO | Use the modulo value in the param struct |

> The param struct is defined as follows

    customNumber_t {
        double range_down; // defaulted to 0.0
        double range_up; // defaulted to 1.0

        double modulo; // defaulted to 1.0
    }