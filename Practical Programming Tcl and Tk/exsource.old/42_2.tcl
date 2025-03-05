#
# Example 42-2
# Telling other applications what your name is.
#

foreach app [winfo interps] {
	catch {send $app [list Iam [tk appname]]}
}


