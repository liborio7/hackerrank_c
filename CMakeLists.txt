cmake_minimum_required(VERSION 3.6)
project(playground)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c
        input_util.c input_util.h
        output_util.c output_util.h
        debug_util.c debug_util.h

        ds_arrays_0_arrays_ds/reverse_array.c ds_arrays_0_arrays_ds/reverse_array.h
        ds_arrays_1_2d_arrays_ds/hourglass.c ds_arrays_1_2d_arrays_ds/hourglass.h
        ds_arrays_2_dynamic_array/dynamic_array.c ds_arrays_2_dynamic_array/dynamic_array.h
        ds_arrays_3_left_rotation/rotate.c ds_arrays_3_left_rotation/rotate.h
        ds_arrays_4_sparse_arrays/matching_strings.c ds_arrays_4_sparse_arrays/matching_strings.h
        ds_arrays_5_array_manipulation/array_manipulation.c ds_arrays_5_array_manipulation/array_manipulation.h

        ds_linked_list/linked_list.c ds_linked_list/linked_list.h
        ds_linked_list_0_insert_tail/insert_head.c ds_linked_list_0_insert_tail/insert_tail.h
        ds_linked_list_1_insert_head/insert_head.c ds_linked_list_1_insert_head/insert_head.h
        ds_linked_list_2_insert_position/insert_position.c ds_linked_list_2_insert_position/insert_position.h)

add_executable(playground ${SOURCE_FILES})