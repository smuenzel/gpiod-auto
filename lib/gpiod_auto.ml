external x : unit -> string array = "x"

type gpiod_chip_info
type gpiod_chip
type gpiod_request_config
type gpiod_line_config
type gpiod_line_request
type gpiod_line_info
type gpiod_line_settings
type gpiod_info_event

type uint32 = int

(*$
open Cppcaml_gen

external x : unit -> string array = "x"

let () =
  print_externals ()

*)
external gpiod_chip_open
  : string -> gpiod_chip
  = "ccwrap__gpiod_chip_open"

external gpiod_chip_get_info
  : gpiod_chip -> gpiod_chip_info
  = "ccwrap__gpiod_chip_get_info"

external gpiod_chip_get_path
  : gpiod_chip -> string
  = "ccwrap__gpiod_chip_get_path"

external gpiod_chip_get_line_info
  : gpiod_chip -> uint32 -> gpiod_line_info
  = "ccwrap__gpiod_chip_get_line_info"

external gpiod_chip_watch_line_info
  : gpiod_chip -> uint32 -> gpiod_line_info
  = "ccwrap__gpiod_chip_watch_line_info"

external gpiod_chip_unwatch_line_info
  : gpiod_chip -> uint32 -> int
  = "ccwrap__gpiod_chip_unwatch_line_info"

external gpiod_chip_get_fd
  : gpiod_chip -> int
  = "ccwrap__gpiod_chip_get_fd"

external gpiod_chip_wait_info_event
  : gpiod_chip -> int64 -> int
  = "ccwrap__gpiod_chip_wait_info_event"

external gpiod_chip_read_info_event
  : gpiod_chip -> gpiod_info_event
  = "ccwrap__gpiod_chip_read_info_event"

external gpiod_chip_get_line_offset_from_name
  : gpiod_chip -> string -> int
  = "ccwrap__gpiod_chip_get_line_offset_from_name"

external gpiod_chip_request_lines
  : gpiod_chip -> gpiod_request_config -> gpiod_line_config -> gpiod_line_request
  = "ccwrap__gpiod_chip_request_lines"

external gpiod_chip_info_get_name
  : gpiod_chip_info -> string
  = "ccwrap__gpiod_chip_info_get_name"

external gpiod_chip_info_get_label
  : gpiod_chip_info -> string
  = "ccwrap__gpiod_chip_info_get_label"

external gpiod_chip_info_get_num_lines
  : gpiod_chip_info -> int
  = "ccwrap__gpiod_chip_info_get_num_lines"

external gpiod_line_info_copy
  : gpiod_line_info -> gpiod_line_info
  = "ccwrap__gpiod_line_info_copy"

external gpiod_line_info_get_offset
  : gpiod_line_info -> uint32
  = "ccwrap__gpiod_line_info_get_offset"

external gpiod_line_info_get_name
  : gpiod_line_info -> string
  = "ccwrap__gpiod_line_info_get_name"

external gpiod_line_info_is_used
  : gpiod_line_info -> bool
  = "ccwrap__gpiod_line_info_is_used"

external gpiod_line_info_get_consumer
  : gpiod_line_info -> string
  = "ccwrap__gpiod_line_info_get_consumer"

external gpiod_line_info_is_active_low
  : gpiod_line_info -> bool
  = "ccwrap__gpiod_line_info_is_active_low"

external gpiod_line_info_is_debounced
  : gpiod_line_info -> bool
  = "ccwrap__gpiod_line_info_is_debounced"

external gpiod_line_info_get_debounce_period_us
  : gpiod_line_info -> int
  = "ccwrap__gpiod_line_info_get_debounce_period_us"

external gpiod_info_event_get_timestamp_ns
  : gpiod_info_event -> int
  = "ccwrap__gpiod_info_event_get_timestamp_ns"

external gpiod_info_event_get_line_info
  : gpiod_info_event -> gpiod_line_info
  = "ccwrap__gpiod_info_event_get_line_info"

external gpiod_line_settings_reset
  : gpiod_line_settings -> unit
  = "ccwrap__gpiod_line_settings_reset"

external gpiod_line_settings_copy
  : gpiod_line_settings -> gpiod_line_settings
  = "ccwrap__gpiod_line_settings_copy"

external gpiod_line_settings_set_active_low
  : gpiod_line_settings -> bool -> unit
  = "ccwrap__gpiod_line_settings_set_active_low"

external gpiod_line_settings_get_active_low
  : gpiod_line_settings -> bool
  = "ccwrap__gpiod_line_settings_get_active_low"

external gpiod_line_settings_set_debounce_period_us
  : gpiod_line_settings -> int -> unit
  = "ccwrap__gpiod_line_settings_set_debounce_period_us"

external gpiod_line_settings_get_debounce_period_us
  : gpiod_line_settings -> int
  = "ccwrap__gpiod_line_settings_get_debounce_period_us"

external gpiod_line_config_get_line_settings
  : gpiod_line_config -> uint32 -> gpiod_line_settings
  = "ccwrap__gpiod_line_config_get_line_settings"

external gpiod_line_config_get_num_configured_offsets
  : gpiod_line_config -> int
  = "ccwrap__gpiod_line_config_get_num_configured_offsets"

(* 32 functions *)
(*$*)


let%expect_test "" =
  Array.iter print_endline (x());
  [%expect {|
    1
    12
    123
    1234
    12345
    123456
    1234567
    12345678
    123456789
    |}]

(*$

let () =
  enum_print_as_comment ()

*)
(* ((name gpiod_line_value) (cpp_name gpiod_line_value) (is_bitflag false)
 (entries
  (((name GPIOD_LINE_VALUE_ERROR) (value -1))
   ((name GPIOD_LINE_VALUE_INACTIVE) (value 0))
   ((name GPIOD_LINE_VALUE_ACTIVE) (value 1))))) *)
(* ((name gpiod_line_direction) (cpp_name gpiod_line_direction)
 (is_bitflag false)
 (entries
  (((name GPIOD_LINE_DIRECTION_AS_IS) (value 1))
   ((name GPIOD_LINE_DIRECTION_INPUT) (value 2))
   ((name GPIOD_LINE_DIRECTION_OUTPUT) (value 3))))) *)
(* ((name gpiod_line_edge) (cpp_name gpiod_line_edge) (is_bitflag false)
 (entries
  (((name GPIOD_LINE_EDGE_NONE) (value 1))
   ((name GPIOD_LINE_EDGE_RISING) (value 2))
   ((name GPIOD_LINE_EDGE_FALLING) (value 3))
   ((name GPIOD_LINE_EDGE_BOTH) (value 4))))) *)
(* ((name gpiod_line_bias) (cpp_name gpiod_line_bias) (is_bitflag false)
 (entries
  (((name GPIOD_LINE_BIAS_AS_IS) (value 1))
   ((name GPIOD_LINE_BIAS_UNKNOWN) (value 2))
   ((name GPIOD_LINE_BIAS_DISABLED) (value 3))
   ((name GPIOD_LINE_BIAS_PULL_UP) (value 4))
   ((name GPIOD_LINE_BIAS_PULL_DOWN) (value 5))))) *)
(* ((name gpiod_line_drive) (cpp_name gpiod_line_drive) (is_bitflag false)
 (entries
  (((name GPIOD_LINE_DRIVE_PUSH_PULL) (value 1))
   ((name GPIOD_LINE_DRIVE_OPEN_DRAIN) (value 2))
   ((name GPIOD_LINE_DRIVE_OPEN_SOURCE) (value 3))))) *)
(* ((name gpiod_line_clock) (cpp_name gpiod_line_clock) (is_bitflag false)
 (entries
  (((name GPIOD_LINE_CLOCK_MONOTONIC) (value 1))
   ((name GPIOD_LINE_CLOCK_REALTIME) (value 2))
   ((name GPIOD_LINE_CLOCK_HTE) (value 3))))) *)
(* ((name gpiod_info_event_type) (cpp_name gpiod_info_event_type)
 (is_bitflag false)
 (entries
  (((name GPIOD_INFO_EVENT_LINE_REQUESTED) (value 1))
   ((name GPIOD_INFO_EVENT_LINE_RELEASED) (value 2))
   ((name GPIOD_INFO_EVENT_LINE_CONFIG_CHANGED) (value 3))))) *)
(* 7 enums *)
(*$*)
