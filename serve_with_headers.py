#!/usr/bin/env python3

from http.server import HTTPServer, SimpleHTTPRequestHandler

class HeaderRequestHandler(SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "require-corp")
        super().end_headers()

if __name__ == '__main__':
    print("Serving on http://localhost:8000. NOTE: will not work on other IP addresses, unless HTTPS is enabled")
    server = HTTPServer(('localhost', 8000), HeaderRequestHandler)
    server.serve_forever()
