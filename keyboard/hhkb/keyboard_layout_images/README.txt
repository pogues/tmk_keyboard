The subdirectories here relate to the keymap_<name>.c file with the same <name>.

The json files in each subdirectory are the layout information for the specified keymap.  They are
the format as produced by http://www.keyboard-layout-editor.com/#/.

The png files are just the images exported (manually) from the above site.

To generate the full_layout file execute the following command (from the imagemagick library),
replacing the names as necessary for the set you have.  The final name is the result file.

convert -append base_layer.png vim_layer.png bracket_layer.png numpad_layer.png full_layout.png
