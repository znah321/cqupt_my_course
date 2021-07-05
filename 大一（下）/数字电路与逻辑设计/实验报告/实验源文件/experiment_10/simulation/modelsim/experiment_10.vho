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

-- DATE "05/22/2020 14:36:49"

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

ENTITY 	lab_1 IS
    PORT (
	F : OUT std_logic_vector(3 DOWNTO 0);
	clk : IN std_logic;
	Y : OUT std_logic_vector(3 DOWNTO 0)
	);
END lab_1;

-- Design Ports Information
-- F[3]	=>  Location: PIN_41,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[2]	=>  Location: PIN_39,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[1]	=>  Location: PIN_38,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- F[0]	=>  Location: PIN_44,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[3]	=>  Location: PIN_101,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[2]	=>  Location: PIN_102,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[1]	=>  Location: PIN_100,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y[0]	=>  Location: PIN_103,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_31,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF lab_1 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_F : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_clk : std_logic;
SIGNAL ww_Y : std_logic_vector(3 DOWNTO 0);
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \F[3]~output_o\ : std_logic;
SIGNAL \F[2]~output_o\ : std_logic;
SIGNAL \F[1]~output_o\ : std_logic;
SIGNAL \F[0]~output_o\ : std_logic;
SIGNAL \Y[3]~output_o\ : std_logic;
SIGNAL \Y[2]~output_o\ : std_logic;
SIGNAL \Y[1]~output_o\ : std_logic;
SIGNAL \Y[0]~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \inst|29~combout\ : std_logic;
SIGNAL \inst|33~0_combout\ : std_logic;
SIGNAL \inst|33~feeder_combout\ : std_logic;
SIGNAL \inst|33~q\ : std_logic;
SIGNAL \inst|32~0_combout\ : std_logic;
SIGNAL \inst|32~q\ : std_logic;
SIGNAL \inst|31~0_combout\ : std_logic;
SIGNAL \inst|31~feeder_combout\ : std_logic;
SIGNAL \inst|31~q\ : std_logic;
SIGNAL \inst|34~0_combout\ : std_logic;
SIGNAL \inst|34~q\ : std_logic;
SIGNAL \inst|7~0_combout\ : std_logic;
SIGNAL \inst|7~feeder_combout\ : std_logic;
SIGNAL \inst|7~q\ : std_logic;
SIGNAL \inst|20~combout\ : std_logic;
SIGNAL \inst|6~0_combout\ : std_logic;
SIGNAL \inst|6~q\ : std_logic;
SIGNAL \inst|5~0_combout\ : std_logic;
SIGNAL \inst|5~q\ : std_logic;
SIGNAL \inst|3~0_combout\ : std_logic;
SIGNAL \inst|3~q\ : std_logic;
SIGNAL \ALT_INV_clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \inst|ALT_INV_7~q\ : std_logic;
SIGNAL \inst|ALT_INV_6~q\ : std_logic;
SIGNAL \inst|ALT_INV_33~q\ : std_logic;
SIGNAL \inst|ALT_INV_31~q\ : std_logic;

BEGIN

F <= ww_F;
ww_clk <= clk;
Y <= ww_Y;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);
\ALT_INV_clk~inputclkctrl_outclk\ <= NOT \clk~inputclkctrl_outclk\;
\inst|ALT_INV_7~q\ <= NOT \inst|7~q\;
\inst|ALT_INV_6~q\ <= NOT \inst|6~q\;
\inst|ALT_INV_33~q\ <= NOT \inst|33~q\;
\inst|ALT_INV_31~q\ <= NOT \inst|31~q\;

-- Location: IOOBUF_X0_Y10_N2
\F[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|31~q\,
	devoe => ww_devoe,
	o => \F[3]~output_o\);

-- Location: IOOBUF_X0_Y11_N9
\F[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|32~q\,
	devoe => ww_devoe,
	o => \F[2]~output_o\);

-- Location: IOOBUF_X0_Y11_N2
\F[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|33~q\,
	devoe => ww_devoe,
	o => \F[1]~output_o\);

-- Location: IOOBUF_X0_Y10_N23
\F[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|34~q\,
	devoe => ww_devoe,
	o => \F[0]~output_o\);

-- Location: IOOBUF_X26_Y0_N9
\Y[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|3~q\,
	devoe => ww_devoe,
	o => \Y[3]~output_o\);

-- Location: IOOBUF_X26_Y0_N2
\Y[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|5~q\,
	devoe => ww_devoe,
	o => \Y[2]~output_o\);

-- Location: IOOBUF_X26_Y0_N16
\Y[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|6~q\,
	devoe => ww_devoe,
	o => \Y[1]~output_o\);

-- Location: IOOBUF_X28_Y0_N30
\Y[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|7~q\,
	devoe => ww_devoe,
	o => \Y[0]~output_o\);

-- Location: IOIBUF_X0_Y14_N1
\clk~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G4
\clk~inputclkctrl\ : cycloneiii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clk~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clk~inputclkctrl_outclk\);

-- Location: LCCOMB_X1_Y11_N6
\inst|29\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|29~combout\ = LCELL((\inst|31~q\) # (!\clk~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \clk~input_o\,
	datad => \inst|31~q\,
	combout => \inst|29~combout\);

-- Location: LCCOMB_X2_Y11_N20
\inst|33~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|33~0_combout\ = !\inst|33~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst|33~q\,
	combout => \inst|33~0_combout\);

-- Location: LCCOMB_X2_Y11_N4
\inst|33~feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|33~feeder_combout\ = \inst|33~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|33~0_combout\,
	combout => \inst|33~feeder_combout\);

-- Location: FF_X2_Y11_N5
\inst|33\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|29~combout\,
	d => \inst|33~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|33~q\);

-- Location: LCCOMB_X2_Y11_N0
\inst|32~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|32~0_combout\ = !\inst|32~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst|32~q\,
	combout => \inst|32~0_combout\);

-- Location: FF_X2_Y11_N1
\inst|32\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|ALT_INV_33~q\,
	d => \inst|32~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|32~q\);

-- Location: LCCOMB_X1_Y11_N28
\inst|31~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|31~0_combout\ = (!\inst|31~q\ & (\inst|33~q\ & \inst|32~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|31~q\,
	datab => \inst|33~q\,
	datac => \inst|32~q\,
	combout => \inst|31~0_combout\);

-- Location: LCCOMB_X1_Y11_N0
\inst|31~feeder\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|31~feeder_combout\ = \inst|31~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|31~0_combout\,
	combout => \inst|31~feeder_combout\);

-- Location: FF_X1_Y11_N1
\inst|31\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_clk~inputclkctrl_outclk\,
	d => \inst|31~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|31~q\);

-- Location: LCCOMB_X1_Y11_N30
\inst|34~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|34~0_combout\ = !\inst|34~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst|34~q\,
	combout => \inst|34~0_combout\);

-- Location: FF_X1_Y11_N31
\inst|34\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|ALT_INV_31~q\,
	d => \inst|34~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|34~q\);

-- Location: LCCOMB_X28_Y8_N30
\inst|7~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|7~0_combout\ = !\inst|7~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst|7~q\,
	combout => \inst|7~0_combout\);

-- Location: LCCOMB_X28_Y8_N20
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

-- Location: FF_X28_Y8_N21
\inst|7\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \ALT_INV_clk~inputclkctrl_outclk\,
	d => \inst|7~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|7~q\);

-- Location: LCCOMB_X28_Y8_N28
\inst|20\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|20~combout\ = LCELL((\inst|3~q\) # (!\inst|7~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst|3~q\,
	datad => \inst|7~q\,
	combout => \inst|20~combout\);

-- Location: LCCOMB_X28_Y8_N18
\inst|6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|6~0_combout\ = !\inst|6~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \inst|6~q\,
	combout => \inst|6~0_combout\);

-- Location: FF_X28_Y8_N29
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

-- Location: LCCOMB_X27_Y8_N16
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

-- Location: FF_X27_Y8_N17
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

-- Location: LCCOMB_X27_Y8_N6
\inst|3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|3~0_combout\ = (\inst|6~q\ & (!\inst|3~q\ & \inst|5~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst|6~q\,
	datac => \inst|3~q\,
	datad => \inst|5~q\,
	combout => \inst|3~0_combout\);

-- Location: FF_X27_Y8_N7
\inst|3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \inst|ALT_INV_7~q\,
	d => \inst|3~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|3~q\);

ww_F(3) <= \F[3]~output_o\;

ww_F(2) <= \F[2]~output_o\;

ww_F(1) <= \F[1]~output_o\;

ww_F(0) <= \F[0]~output_o\;

ww_Y(3) <= \Y[3]~output_o\;

ww_Y(2) <= \Y[2]~output_o\;

ww_Y(1) <= \Y[1]~output_o\;

ww_Y(0) <= \Y[0]~output_o\;
END structure;


