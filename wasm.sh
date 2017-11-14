FUNS="['_make_image', '_make_board', '_draw_board', '_increment', '_make_patch', '_apply', '_velocity_patch', '_deflection_patch']"
NAME=$(find ./src -name '*.c')
emcc -O3 $NAME -s WASM=1 -s EXPORTED_FUNCTIONS="$FUNS" -s NO_EXIT_RUNTIME=1 --shell-file index.html -o out/hello.html

