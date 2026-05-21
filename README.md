### Init project
```
swift package init --name MyCLI --type executable
```

### To Run CLI app
```
swift run structyCLI
```

### Test
```
PKG_CONFIG_PATH=/usr/lib/x86_64-linux-gnu/pkgconfig swift test
```


### To clean project (Cached pch files - headers)
```
rm -rf .build
```

