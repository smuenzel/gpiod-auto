

external x : unit -> string = "x"


let%expect_test "" =
  print_endline (x ());
  [%expect {| 0 |}];
