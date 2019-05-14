{
  "targets": [
    {
      "target_name": "helloworld",
      "sources": [ 
        "src/hello.cc" 
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}