- [x] handle connection failures
- [x] add some basic method to determine if parameter is correct 
- [x] paralellize tests
- [x] refactor all this config mess (templates!)
- [x] handle reflected params
- [x] add progress bar
- [x] support POST, PUT, DELETE
- [x] support reading requests from txt file
- [x] support passing headers
- [x] support passing cookies
- [x] add a switch to recognize valid parameters based on presence of some string in the response
- [x] add a switch to recognize valid parameters based on lack of presence of some string in the response
- [x] refactor main function (extract config display logic)
- [ ] make some better banner and overall output presentation
- [ ] cache requests made only to obtain response length and reuse those lengths later
- [x] match / filter response codes
- [ ] use string_views instead of const string ref
- [x] add support for response len range (+- 5 etc)
- [x] check response codes before response len
- [x] specify user-agent
- [x] http proxy!
- [x] fix a '=' in get body bug
- [ ] support keywords like RPARAM and RVALUE in custom places to be replaced with param names and values
- [ ] support reading crlf files
