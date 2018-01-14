The json files here are the layout information for the keymap_vim setup.  They are the format as
produced by http://www.keyboard-layout-editor.com/#/.

The png files are just the images exported from the above site.

To generate the full_layout file execute the following command (from the imagemagick library)

convert -append base_layer.png vim_layer.png bracket_layer.png numpad_layer.png full_layout.png
