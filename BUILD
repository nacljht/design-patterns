load("@gazelle//:def.bzl", "gazelle", "gazelle_binary")

# Define a gazelle binary with a list of enabled extensions
## Exclude following subtrees from being managed by gazelle. Be aware that it also prevents other targets from automatic dependency resolution in these modules using gazelle
# gazelle:exclude third-party
# gazelle:exclude examples/usage

## Define how the cc sources should be managed, use `unit` for small file-based targets.
# gazelle:cc_group unit

## Warn if there are some unresolved cyclic dependencies between source files
# gazelle:cc_group_unit_cycles warn

## Overwrite how some C/C++ includes should be resolved
# gazelle:resolve cc gtest/gtest.h @googletest//:gtest_main
# gazelle:resolve cc fmt.h @googletest//:gtest_main
gazelle_binary(
    name = "gazelle_cc",
    languages = [
        "@gazelle//language/proto",
        "@gazelle//language/go",
        "@gazelle_cc//language/cc",
    ],
)

# `gazelle` rule can be used to provide additional arguments, eg. for CI integration
gazelle(
    name = "gazelle",
    gazelle = ":gazelle_cc",
)
