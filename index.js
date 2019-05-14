const helloworld = require("./build/release/helloworld");
console.log(helloworld)
console.log( helloworld.value && helloworld.value() )
console.log( helloworld.display && helloworld.display("Something") )