# node-nan-hello-world
Node.js - C++ Addons - Native Abstractions for Node.js

- mkdir src
- touch src/hello.cc
- touch binding.gyp
- touch index.js
- npm init -y
- npm i nan

- node-gyp configure
- node-gyp build
```
{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ 
        "src/hello.cc" 
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}
```

```
// index.js
const helloworld = require("./build/release/helloworld");
console.log( helloworld.value() )
```