var console = new Duktape.Logger(null);
console.log = console.info;

function extend (obj) {
	var source, prop;
	for (var i = 1, length = arguments.length; i < length; i++) {
  		source = arguments[i];
  		for (prop in source) {
    		if (hasOwnProperty.call(source, prop)) {
    	    	obj[prop] = source[prop];
    		}
  		}
	}
	return obj;
}

function s(props) {
	var defaults = {
		width: 100, height: 100,
		backgroundColor: [1.0, 0.0, 1.0, 1.0],
		padding: [0, 0, 0, 0],
		margin: [0, 0, 0, 0],
	}

	if (typeof props.padding == 'number') {
		var p = props.padding;
		props.padding = [p, p, p, p];
	}

	if (typeof props.margin == 'number') {
		var p = props.margin;
		props.margin = [p, p, p, p];
	}

	return extend(defaults, props);
}
var size = 300;
var res = createSurface(s({
	width: 1280,
	height: 720,
	flexDirection: 'row',
	flexWrap: 'wrap',
	background: "../../example/textures/black_bg.dds",
	children: [
		s({width: 1280, height: 50, text: ["Simple flexbox UI layout with Twinkle!", 50], margin: 30}),
		s({width: size, height: size, background: "../../example/textures/hello_saferide.dds", margin: 5}),
		s({width: size, height: size, background: "../../example/textures/hakan_tva_steg.dds", margin: 5}),
		s({width: size, height: size, background: "../../example/textures/shout_out_louds.dds", margin: 5}),
		s({width: size, height: size, background: "../../example/textures/counting_crows.dds", margin: 5}),
		s({width: size, height: size, text: ["Twinkle, twinkle, little subpixeled text!", 12], margin: 5}),
	]
}));

console.log("HELLO WORLD!");