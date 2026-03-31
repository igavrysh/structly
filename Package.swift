// swift-tools-version: 6.0.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MyCLI",
    platforms: [.macOS(.v14)],
    products: [
        .library(name: "structy", targets: ["structy"]),
        .library(name: "structyC", targets: ["structyC"]),
        .executable(name: "structyCLI", targets: ["structyCLI"])
    ],
    targets: [
        .target(
            name: "structy",
            dependencies: ["structyC"],
            path: "Sources/structy",
            swiftSettings: [
                .interoperabilityMode(.Cxx),
                .enableUpcomingFeature("StrictConcurrency"),
                .swiftLanguageMode(.v6)
            ]
        ),
        .target(
            name: "lc",
            dependencies: [],
            path: "Sources/lc",
            swiftSettings: [
                .interoperabilityMode(.Cxx),
                .enableUpcomingFeature("StrictConcurrency"),
                .swiftLanguageMode(.v6)
            ]
        ),
        .target(
            name: "structyC",
            dependencies: [],
            path: "Sources/structyC",
            publicHeadersPath: "include",
            swiftSettings: [.interoperabilityMode(.Cxx)]
        ),

        .executableTarget(
            name: "structyCLI",
            dependencies: ["structy"],
            swiftSettings: [
                .interoperabilityMode(.Cxx),
                .enableUpcomingFeature("StrictConcurrency"),
                .swiftLanguageMode(.v6)
            ],
            linkerSettings: [
                .linkedLibrary("m", .when(platforms: [.linux])) 
            ]
        ),

        .testTarget(
            name: "lcTests",
            dependencies: ["lc"],
            path: "Tests/lcTests",
            swiftSettings: [.interoperabilityMode(.Cxx)]

        )
    ],
    cxxLanguageStandard: .cxx17 // Explicitly set the C++ version
)
