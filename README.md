# Notes

* You must specify the number of threads available at compile time
* Spawning more threads will cause cause it to crash
* The web server that is serving the HTML/JS/WASM module must provide the following hTML headers

    Cross-Origin-Opener-Policy: same-origin
    Cross-Origin-Embedded-Policy: require-copr

* You MUST serve the webpage using HTTPS, unless you only allowing localhost to view the page
* An example python webserver

