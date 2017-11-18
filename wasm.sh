MAIN="'_main', '_increment', '_destruct', '_set_timestep', '_get_time', '_velocity_table', '_deflection_table'"
REGULAR="'_make_regular_board'"
PATCH="'_make_table', '_apply_patch', '_make_phase_table', 'apply_phase_patch'"
DRAW="'_draw_board', '_make_image'"
FUNS="[$MAIN, $REGULAR, $PATCH, $DRAW]"
NAME=$(find ./src -name '*.c')
emcc -O3 $NAME -s WASM=1 -s EXPORTED_FUNCTIONS="$FUNS" -s NO_EXIT_RUNTIME=1 --shell-file index.html -o out/hello.html

