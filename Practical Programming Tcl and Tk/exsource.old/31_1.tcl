#
# Example 31-1
# A text widget and two scrollbars.
#

proc Scrolled_Text { f args } {
	frame $f
	eval {text $f.text -wrap none \
		-xscrollcommand [list $f.xscroll set] \
		-yscrollcommand [list $f.yscroll set]} $args
	scrollbar $f.xscroll -orient horizontal \
		-command [list $f.text xview]
	scrollbar $f.yscroll -orient vertical \
		-command [list $f.text yview]
	grid $f.text $f.yscroll -sticky news
	grid $f.xscroll -sticky news
	grid rowconfigure $f 0 -weight 1
	grid columnconfigure $f 0 -weight 1
	return $f.text
}
set t [Scrolled_Text .f -width 40 -height 8]
pack .f -side top -fill both -expand true
set in [open /etc/passwd]
$t insert end [read $in]
close $in


