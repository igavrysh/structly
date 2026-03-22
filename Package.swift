// swift-tools-version: 6.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MyCLI",
    platforms: [.macOS(.v14)],
    products: [
        .library(name: "structly", targets: ["structly"]),
        .library(name: "structlyC", targets: ["structlyC"]),
        .executable(name: "structlyCLI", targets: ["structlyCLI"])
    ],
    targets: [
        .target(
            name: "structly",
            dependencies: ["structlyC"],
            path: "Sources/structly",
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),
        .target(
            name: "structlyC",
            dependencies: [],
            path: "Sources/structlyC",
            publicHeadersPath: "include",
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),

        .executableTarget(
            name: "structlyCLI",
            dependencies: ["structly"],
            swiftSettings: [.interoperabilityMode(.Cxx)],
            linkerSettings: [
                .linkedLibrary("m", .when(platforms: [.linux])) 
            ]
        ),

        .testTarget(
            name: "structlyTests",
            dependencies: ["structly"],
            path: "Tests/structlyTests",
            swiftSettings: [.interoperabilityMode(.Cxx)]

        )
    ],
    cxxLanguageStandard: .cxx17 // Explicitly set the C++ version
)
