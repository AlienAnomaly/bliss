{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
	let
		system = "x86_64-linux";
		pkgs = import nixpkgs { inherit system; };
	in {
		devShells.${system}.default = pkgs.mkShell {
			packages = with pkgs; [
				gcc
				cmake
				meson
				ninja
				sdl3
				sdl3-image
				pkg-config
			];
			
			shellHook = ''
				echo "Dev environment initializing..."
			'';
		};
	};

}
