(lang dune 3.17)

(name gpiod_auto)

(generate_opam_files true)

(source
 (github smuenzel/gpiod-auto))

(authors "Stefan Muenzel <source@s.muenzel.net>")

(maintainers "Stefan Muenzel <source@s.muenzel.net>")

(license MPL-2.0)

(documentation https://url/to/documentation)

(package
 (name gpiod_auto)
 (synopsis "Ocaml interface to libgpiod")
 (description "Ocaml interface to libgpiod")
 (depends ocaml)
 (tags
  ("gpio" "libgpiod")))

; See the complete stanza docs at https://dune.readthedocs.io/en/stable/reference/dune-project/index.html
