. $EMSDK_ENV
MAIN="'_affine', '_normalize', '_increment', '_destruct', '_set_timestep', '_get_time', '_velocity_table', '_deflection_table'"
REGULAR="'_make_regular_board', '_set_acceleration', '_set_damping'"
PATCH="'_make_table', '_free_table', '_apply_patch', '_make_phase_table', 'apply_phase_patch'"
DRAW="'_draw_table', '_make_image', '_free_image', '_make_palette', '_free_palette', '_draw_with_palette'"
FUNS="[$MAIN, $REGULAR, $PATCH, $DRAW]"
NAME=$(find ./src -name '*.c')
emcc -O3 $NAME -s WASM=1 -s EXPORTED_FUNCTIONS="$FUNS" -s NO_EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -o out/wasm.js

