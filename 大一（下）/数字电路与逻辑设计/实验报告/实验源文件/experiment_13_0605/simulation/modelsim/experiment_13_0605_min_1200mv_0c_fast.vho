-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Full Version"

-- DATE "06/05/2020 15:28:11"

-- 
-- Device: Altera EP3C16Q240C8 Package PQFP240
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	lab1 IS
    PORT (
	seq : OUT std_logic_vector(6 DOWNTO 0);
	CP : IN std_logic
	);
END lab1;

-- Design Ports Information
-- seq[6]	=>  Location: PIN_73,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[5]	=>  Location: PIN_64,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[4]	=>  Location: PIN_68,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[3]	=>  Location: PIN_65,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[2]	=>  Location: PIN_70,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[1]	=>  Location: PIN_71,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- seq[0]	=>  Location: PIN_69,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CP	=>  Location: PIN_72,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF lab1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_seq : std_logic_vector(6 DOWNTO 0);
SIGNAL ww_CP : std_logic;
SIGNAL \seq[6]~output_o\ : std_logic;
SIGNAL \seq[5]~output_o\ : std_logic;
SIGNAL \seq[4]~output_o\ : std_logic;
SIGNAL \seq[3]~output_o\ : std_logic;
SIGNAL \seq[2]~output_o\ : std_logic;
SIGNAL \seq[1]~output_o\ : std_logic;
SIGNAL \seq[0]~output_o\ : std_logic;
SIGNAL \CP~input_o\ : std_logic;
SIGNAL \inst|7~0_combout\ : std_logic;
SIGNAL \inst|7~feeder_combout\ : std_logic;
SIGNAL \inst|7~q\ : std_logic;
SIGNAL \inst|3~0_combout\ : std_logic;
SIGNAL \inst|3~feeder_combout\ : std_logic;
SIGNAL \inst|3~q\ : std_logic;
SIGNAL \inst|20~combout\ : std_logic;
SIGNAL \inst|6~0_combout\ : std_logic;
SIGNAL \inst|6~q\ : std_logic;
SIGNAL \inst|5~0_combout\ : std_logic;
SIGNAL \inst|5~q\ : std_logic;
SIGNAL \inst2|72~combout\ : std_logic;
SIGNAL \inst2|66~0_combout\ : std_logic;
SIGNAL \inst2|71~combout\ : std_logic;
SIGNAL \inst2|67~0_combout\ : std_logic;
SIGNAL \inst2|70~combout\ : std_logic;
SIGNAL \inst2|68~0_combout\ : std_logic;
SIGNAL \inst2|69~0_combout\ : std_logic;
SIGNAL \ALT_INV_CP~input_o\ : std_logic;
SIGNAL \inst2|ALT_INV_69~0_combout\ : std_logic;
SIGNAL \inst2|ALT_INV_68~0_combout\ : std_logic;
SIGNAL \inst2|ALT_INV_70~combout\ : std_logic;
SIGNAL \inst2|ALT_INV_71~combout\ : std_logic;
SIGNAL \inst2|ALT_INV_66~0_combout\ : std_logic;
SIGNAL \inst2|ALT_INV_72~combout\ : std_logic;
SIGNAL \inst|ALT_INV_6~q\ : std_logic;
SIGNAL \inst|ALT_INV_7~q\ : std_logic;

BEGIN

seq <= ww_seq;
ww_CP <= CP;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_CP~input_o\ <= NOT \CP~input_o\;
\inst2|ALT_INV_69~0_combout\ <= NOT \inst2|69~0_combout\;
\inst2|ALT_INV_68~0_combout\ <= NOT \inst2|68~0_combout\;
\inst2|ALT_INV_70~combout\ <= NOT \inst2|70~combout\;
\inst2|ALT_INV_71~combout\ <= NOT \inst2|71~combout\;
\inst2|ALT_INV_66~0_combout\ <= NOT \inst2|66~0_combout\;
\inst2|ALT_INV_72~combout\ <= NOT \inst2|72~combout\;
\inst|ALT_INV_6~q\ <= NOT \inst|6~q\;
\inst|ALT_INV_7~q\ <= NOT \inst|7~q\;

-- Location: IOOBUF_X7_Y0_N9
\seq[6]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_72~combout\,
	devoe => ww_devoe,
	o => \seq[6]~output_o\);

-- Location: IOOBUF_X5_Y0_N30
\seq[5]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_66~0_combout\,
	devoe => ww_devoe,
	o => \seq[5]~output_o\);

-- Location: IOOBUF_X5_Y0_N9
\seq[4]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_71~combout\,
	devoe => ww_devoe,
	o => \seq[4]~output_o\);

-- Location: IOOBUF_X5_Y0_N23
\seq[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|67~0_combout\,
	devoe => ww_devoe,
	o => \seq[3]~output_o\);

-- Location: IOOBUF_X7_Y0_N30
\seq[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_70~combout\,
	devoe => ww_devoe,
	o => \seq[2]~output_o\);

-- Location: IOOBUF_X7_Y0_N23
\seq[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_68~0_combout\,
	devoe => ww_devoe,
	o => \seq[1]~output_o\);

-- Location: IOOBUF_X5_Y0_N2
\seq[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst2|ALT_INV_69~0_combout\,
	devoe => ww_devoe,
	o => \seq[0]~output_o\);

-- Location: IOIBUF_X7_Y0_N15
\CP~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CP,
	o => \CP~input_o\);

-- Location: LCCOMB_X7_Y1_N10
\inst|7~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|7~0_combout\ = !\inst|7~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|7~q\,
	combout => \inst|7~0_combout\);

-- Location: LCCOMB_X7_Y1_N6
\inst|7~feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|7~feeder_combout\ = \inst|7~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|7~0_combout\,
	combout => \inst|7~feeder_combout\);

-- Location: FF_X7_Y1_N7
\inst|7\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_CP~input_o\,
	d => \inst|7~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|7~q\);

-- Location: LCCOMB_X6_Y1_N24
\inst|3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|3~0_combout\ = (\inst|6~q\ & (!\inst|3~q\ & \inst|5~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|6~q\,
	datac => \inst|3~q\,
	datad => \inst|5~q\,
	combout => \inst|3~0_combout\);

-- Location: LCCOMB_X6_Y1_N22
\inst|3~feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|3~feeder_combout\ = \inst|3~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst|3~0_combout\,
	combout => \inst|3~feeder_combout\);

-- Location: FF_X6_Y1_N23
\inst|3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|ALT_INV_7~q\,
	d => \inst|3~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|3~q\);

-- Location: LCCOMB_X6_Y1_N6
\inst|20\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|20~combout\ = LCELL((\inst|3~q\) # (!\inst|7~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|3~q\,
	datad => \inst|7~q\,
	combout => \inst|20~combout\);

-- Location: LCCOMB_X6_Y1_N16
\inst|6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|6~0_combout\ = !\inst|6~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst|6~q\,
	combout => \inst|6~0_combout\);

-- Location: FF_X6_Y1_N7
\inst|6\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|20~combout\,
	asdata => \inst|6~0_combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|6~q\);

-- Location: LCCOMB_X7_Y1_N4
\inst|5~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|5~0_combout\ = !\inst|5~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst|5~q\,
	combout => \inst|5~0_combout\);

-- Location: FF_X7_Y1_N5
\inst|5\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|ALT_INV_6~q\,
	d => \inst|5~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|5~q\);

-- Location: LCCOMB_X7_Y1_N28
\inst2|72\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|72~combout\ = (\inst|5~q\ & (\inst|6~q\ & (\inst|7~q\))) # (!\inst|5~q\ & (!\inst|6~q\ & ((!\inst|3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000010010001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datab => \inst|6~q\,
	datac => \inst|7~q\,
	datad => \inst|3~q\,
	combout => \inst2|72~combout\);

-- Location: LCCOMB_X6_Y1_N26
\inst2|66~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|66~0_combout\ = (\inst|5~q\ & (\inst|6~q\ & ((\inst|7~q\)))) # (!\inst|5~q\ & ((\inst|6~q\) # ((!\inst|3~q\ & \inst|7~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110101000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datab => \inst|6~q\,
	datac => \inst|3~q\,
	datad => \inst|7~q\,
	combout => \inst2|66~0_combout\);

-- Location: LCCOMB_X6_Y1_N14
\inst2|71\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|71~combout\ = (\inst|7~q\) # ((\inst|5~q\ & !\inst|6~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datac => \inst|6~q\,
	datad => \inst|7~q\,
	combout => \inst2|71~combout\);

-- Location: LCCOMB_X6_Y1_N30
\inst2|67~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|67~0_combout\ = (\inst|5~q\ & (\inst|6~q\ $ (\inst|7~q\))) # (!\inst|5~q\ & ((\inst|6~q\) # (!\inst|7~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101011110101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datac => \inst|6~q\,
	datad => \inst|7~q\,
	combout => \inst2|67~0_combout\);

-- Location: LCCOMB_X7_Y1_N0
\inst2|70\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|70~combout\ = (\inst|5~q\ & (((\inst|3~q\)))) # (!\inst|5~q\ & (\inst|6~q\ & (!\inst|7~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datab => \inst|6~q\,
	datac => \inst|7~q\,
	datad => \inst|3~q\,
	combout => \inst2|70~combout\);

-- Location: LCCOMB_X7_Y1_N12
\inst2|68~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|68~0_combout\ = (\inst|6~q\ & ((\inst|3~q\) # ((\inst|5~q\ & !\inst|7~q\)))) # (!\inst|6~q\ & (\inst|5~q\ & (\inst|7~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110000101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datab => \inst|6~q\,
	datac => \inst|7~q\,
	datad => \inst|3~q\,
	combout => \inst2|68~0_combout\);

-- Location: LCCOMB_X6_Y1_N28
\inst2|69~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst2|69~0_combout\ = (\inst|5~q\ & (((\inst|6~q\ & \inst|3~q\)) # (!\inst|7~q\))) # (!\inst|5~q\ & ((\inst|6~q\ & (\inst|3~q\)) # (!\inst|6~q\ & (!\inst|3~q\ & \inst|7~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000111101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|5~q\,
	datab => \inst|6~q\,
	datac => \inst|3~q\,
	datad => \inst|7~q\,
	combout => \inst2|69~0_combout\);

ww_seq(6) <= \seq[6]~output_o\;

ww_seq(5) <= \seq[5]~output_o\;

ww_seq(4) <= \seq[4]~output_o\;

ww_seq(3) <= \seq[3]~output_o\;

ww_seq(2) <= \seq[2]~output_o\;

ww_seq(1) <= \seq[1]~output_o\;

ww_seq(0) <= \seq[0]~output_o\;
END structure;


