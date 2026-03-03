// swift-tools-version: 6.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MyCLI",
    targets: [
        .target(name: "structly"),

        .executableTarget(
            name: "structly-cli",
            dependencies: ["structly"]
        ),

        .testTarget(
            name: "structlyTests",
            dependencies: ["structly"]
        )
    ]
)
