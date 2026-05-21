// swift-tools-version: 6.0

import PackageDescription

let swift6Settings: [SwiftSetting] = [
    .interoperabilityMode(.Cxx),
    .enableUpcomingFeature("StrictConcurrency"),
    .swiftLanguageMode(.v6),
]

let package = Package(
    name: "structy",
    platforms: [
        .macOS(.v14),
    ],
    products: [
        .library(name: "structy", targets: ["structy"]),
        .library(name: "structyC", targets: ["structyC"]),
        .library(name: "lc", targets: ["lc"]),
        .executable(name: "structyCLI", targets: ["structyCLI"]),
    ],
    targets: [
        .target(
            name: "structy",
            dependencies: ["structyC"],
            path: "Sources/structy",
            swiftSettings: swift6Settings
        ),
        .target(
            name: "structyC",
            path: "Sources/structyC",
            publicHeadersPath: "include"
        ),
        .target(
            name: "lc",
            path: "Sources/lc",
            exclude: ["random/lc2452.cpp"]
        ),
        .executableTarget(
            name: "structyCLI",
            dependencies: ["structy", "structyC"],
            path: "Sources/structyCLI",
            swiftSettings: swift6Settings,
            linkerSettings: [
                .linkedLibrary("m", .when(platforms: [.linux])),
            ]
        ),
        .testTarget(
            name: "structyTests",
            dependencies: ["structy"],
            path: "Tests/structyTests"
        ),
        .testTarget(
            name: "lcTests",
            dependencies: ["lc"],
            path: "Tests/lcTests"
        ),
    ],
    cxxLanguageStandard: .cxx17
)
