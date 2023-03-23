#!/usr/bin/env python3


import os


def generate_concavum_h(
    row_vals, col_vals, thumb_vals, indent_width, half_pad, col_pad
):
    """
    Generate the file 'concavum.h' to define the layout for all valid
    combinations of ROWS, COLS and THUMB_KEYS
    """
    max_rows = max(row_vals)
    max_cols = max(max(col_vals), max(thumb_vals))
    indent = " " * indent_width
    # initialize file content string
    out = (
        "#ifndef CONCAVUM_H\n#define CONCAVUM_H\n\n"
        "/* This file was automatically generated. For modifications, use\n"
        " * the provided python script 'generate-concavum-h.py' instead.\n"
        ' */\n\n#include "quantum.h"\n\n'
        "#define XXX KC_NO\n\n"
        "// define LAYOUT and _GET_ROW_PINS depending on ROWS, COLS and THUMB_KEYS\n#"
    )
    # generate all possible LAYOUT and GET_ROW_PIN macros
    for rows in row_vals:
        out += (
            f"if ROWS == {rows}\n"
            + indent
            + generate_get_row_pins(rows, max_rows)
            + indent
            + "#"
        )
        for cols in col_vals:
            out += f"if COLS == {cols}\n" + 2 * indent + "#"
            for t_keys in thumb_vals:
                out += (
                    f"if THUMB_KEYS == {t_keys}\n"
                    + generate_layout(
                        rows, cols, t_keys, max_cols, 3 * indent, half_pad, col_pad
                    )
                    + 2 * indent
                    + "#el"
                )
            out += (
                "se\n"
                + 3 * indent
                + f"#error THUMB_KEYS is not in {thumb_vals}.\n"
                + 2 * indent
                + "#endif\n"
                + indent
                + "#el"
            )
        out += (
            "se\n"
            + 2 * indent
            + f"#error COLS is not in {col_vals}.\n"
            + indent
            + "#endif\n#el"
        )
    out += f"se\n  #error ROWS is not in {row_vals}.\n#endif\n\n"
    # select actually used row pins with previously defined GET_ROW_PINS macro
    out += (
        "// double define allows macros to work within GET_ROW_PINS\n"
        "#define GET_ROW_PINS(...) _GET_ROW_PINS(__VA_ARGS__)\n\n"
        "// select actually used row pins with previously defined macro\n"
        "#define SECONDARY_ROW_PINS  GET_ROW_PINS(ALL_SECONDARY_ROW_PINS)\n"
    )
    # close include guard
    out += "\n#endif\n"
    # write content string to file
    with open(os.path.join(os.path.dirname(__file__), "concavum.h"), "w") as f:
        f.write(out)


def generate_get_row_pins(rows, max_rows):
    """
    Generate the _GET_ROW_PINS macro for a given value of ROWS
    """
    all_rows = [f"p{i:X}" for i in range(max_rows + 1)]
    out = (
        f"#define _GET_ROW_PINS({', '.join(all_rows)})"
        f" {{ {', '.join(all_rows[:rows + 1])} }}\n"
    )
    return out


def generate_layout(rows, cols, thumb_keys, max_cols, indent, half_pad, col_pad):
    """
    Generate the LAYOUT macro for a given values of ROWS, COLS
    and THUMB_KEYS
    """
    # macro arguments
    out = indent + "#define LAYOUT( \\\n"
    # for the finger rows
    for row in range(rows):
        out += indent + (5 * (max_cols - cols) + 6 - col_pad) * " "
        for col in range(2 * cols):
            if col == cols:
                out += (half_pad + 2 * col_pad) * " "
            out += f"k{row:X}{col:X}, "
        out += "\\\n"
    # for the thumb row
    out += indent + (5 * (max_cols - thumb_keys) + 6) * " "
    for t_key in range(2 * thumb_keys):
        if t_key == thumb_keys:
            out += half_pad * " "
        out += f"k{rows:X}{t_key:X}" + (", " if t_key < 2 * thumb_keys - 1 else " ")
    out += "\\\n" + indent + ") { \\\n"
    # corresponding array entries
    # for the thumb row
    num_xxx = (max_cols - thumb_keys)
    out += indent + "    { "
    for i in range(num_xxx):
        out += "XXX, "
    for t_key in range(2 * thumb_keys):
        if t_key == thumb_keys:
            out += half_pad * " "
        out += f"k{rows:X}{t_key:X}" + (", " if t_key < 2 * max_cols - 1 else " ")
    for i in range(num_xxx):
        out += "XXX, " if i < num_xxx - 1 else "XXX "
    out += "}, \\\n"
    # for the finger rows
    num_xxx = max_cols - cols
    for row in range(rows - 1, -1, -1):
        out += indent + "    { "
        for i in range(num_xxx):
            out += "XXX, "
        for col in range(2 * cols):
            if col == cols:
                out += half_pad * " "
            out += f"k{row:X}{col:X}" + (", " if col < 2 * max_cols - 1 else " ")
        for i in range(num_xxx):
            out += "XXX, " if i < num_xxx - 1 else "XXX "
        out += "}, \\\n"
    out += indent + "}\n"
    return out


if __name__ == "__main__":
    # all valid ROWS, COLS and THUMB_KEYS values
    row_vals = [1, 2, 3, 4, 5]
    col_vals = thumb_vals = [1, 2, 3, 4, 5, 6]
    # indentation width for the generated file
    indent_width = 2
    # amount of padding between both halves in LAYOUT macros
    half_pad = 4
    # additional padding between both halves compared to the thumb row
    col_pad = 2
    # generate file content and write it to 'concavum.h'
    generate_concavum_h(row_vals, col_vals, thumb_vals, indent_width, half_pad, col_pad)
