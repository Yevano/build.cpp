function runcmd($cmd) {
    echo ("> " + $cmd);
    return (iex $cmd);
}

if(-not (Test-Path "build")) {
    runcmd("mkdir build")
}

runcmd("g++ -O0 -std=c++2a -fconcepts -I`"yevano.cpp`" build.cpp compiler.cpp api/api.cpp yevano.cpp/win_error.cpp -o build/build.cpp.exe `"-Wl,--out-implib=build/libbuild.cpp.dll.a`"");