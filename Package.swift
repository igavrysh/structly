// swift-tools-version: 6.0

import PackageDescription

let cxxInteropSettings: [SwiftSetting] = [
    .interoperabilityMode(.Cxx),
]

let package = Package(
    name: "structy",
    platforms: [
        .macOS(.v10_15),
    ],
    products: [
        .library(name: "structy", targets: ["structy"]),
        .library(name: "structyC", targets: ["structyC"]),
        .library(name: "lc", targets: ["lc"]),
        .executable(name: "structyCLI", targets: ["structyCLI"]),
    ],
    dependencies: [
        .package(url: "https://github.com/swiftlang/swift-testing.git", from: "6.3.2"),
    ],
    targets: [
        .target(
            name: "structy",
            path: "Sources/structy",
            exclude: ["01_big_o/callCpp.swift"]
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
            swiftSettings: cxxInteropSettings,
            linkerSettings: [
                .linkedLibrary("m", .when(platforms: [.linux])),
            ]
        ),
        .testTarget(
            name: "structyTests",
            dependencies: [
                "structy",
                .product(name: "Testing", package: "swift-testing"),
            ],
            path: "Tests/structyTests"
        ),
        .testTarget(
            name: "lcTests",
            dependencies: [
                "lc",
                .product(name: "Testing", package: "swift-testing"),
            ],
            path: "Tests/lcTests"
        ),
    ],
    cxxLanguageStandard: .cxx17
)
