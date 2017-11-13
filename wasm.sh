NAME=$(find ./src -name '*.c')
emcc $NAME -s WASM=1 -s EXPORTED_FUNCTIONS="['_main', '_alloc']" -s NO_EXIT_RUNTIME=1 --shell-file index.html -o out/hello.html

