external x : unit -> string array = "x"


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
