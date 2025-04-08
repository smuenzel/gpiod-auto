external x : unit -> string array = "x"

type gpiod_chip_info
type gpiod_chip
type gpiod_request_config
type gpiod_line_config
type gpiod_line_request
type gpiod_line_info
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

(* 14 functions *)
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
