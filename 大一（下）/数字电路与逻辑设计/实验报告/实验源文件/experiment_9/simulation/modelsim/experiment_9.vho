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

-- DATE "05/20/2020 19:39:26"

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
	Q : OUT std_logic_vector(3 DOWNTO 0);
	CLK : IN std_logic;
	CLRN : IN std_logic;
	S1 : IN std_logic;
	S0 : IN std_logic
	);
END lab1;

-- Design Ports Information
-- Q[3]	=>  Location: PIN_50,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[2]	=>  Location: PIN_51,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[1]	=>  Location: PIN_52,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Q[0]	=>  Location: PIN_55,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S0	=>  Location: PIN_49,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- S1	=>  Location: PIN_46,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLK	=>  Location: PIN_31,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLRN	=>  Location: PIN_32,	 I/O Standard: 2.5 V,	 Current Strength: Default


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
SIGNAL ww_Q : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_CLK : std_logic;
SIGNAL ww_CLRN : std_logic;
SIGNAL ww_S1 : std_logic;
SIGNAL ww_S0 : std_logic;
SIGNAL \CLK~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLRN~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \Q[3]~output_o\ : std_logic;
SIGNAL \Q[2]~output_o\ : std_logic;
SIGNAL \Q[1]~output_o\ : std_logic;
SIGNAL \Q[0]~output_o\ : std_logic;
SIGNAL \CLK~input_o\ : std_logic;
SIGNAL \CLK~inputclkctrl_outclk\ : std_logic;
SIGNAL \S0~input_o\ : std_logic;
SIGNAL \S1~input_o\ : std_logic;
SIGNAL \inst|41~0_combout\ : std_logic;
SIGNAL \CLRN~input_o\ : std_logic;
SIGNAL \CLRN~inputclkctrl_outclk\ : std_logic;
SIGNAL \inst|41~q\ : std_logic;
SIGNAL \inst|36~0_combout\ : std_logic;
SIGNAL \inst|36~1_combout\ : std_logic;
SIGNAL \inst|40~q\ : std_logic;
SIGNAL \inst|35~0_combout\ : std_logic;
SIGNAL \inst|35~1_combout\ : std_logic;
SIGNAL \inst|39~q\ : std_logic;
SIGNAL \inst|34~0_combout\ : std_logic;
SIGNAL \inst|38~q\ : std_logic;

BEGIN

Q <= ww_Q;
ww_CLK <= CLK;
ww_CLRN <= CLRN;
ww_S1 <= S1;
ww_S0 <= S0;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\CLK~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLK~input_o\);

\CLRN~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLRN~input_o\);

-- Location: IOOBUF_X0_Y5_N16
\Q[3]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|38~q\,
	devoe => ww_devoe,
	o => \Q[3]~output_o\);

-- Location: IOOBUF_X0_Y5_N23
\Q[2]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|39~q\,
	devoe => ww_devoe,
	o => \Q[2]~output_o\);

-- Location: IOOBUF_X0_Y4_N2
\Q[1]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|40~q\,
	devoe => ww_devoe,
	o => \Q[1]~output_o\);

-- Location: IOOBUF_X0_Y4_N23
\Q[0]~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|41~q\,
	devoe => ww_devoe,
	o => \Q[0]~output_o\);

-- Location: IOIBUF_X0_Y14_N1
\CLK~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLK,
	o => \CLK~input_o\);

-- Location: CLKCTRL_G4
\CLK~inputclkctrl\ : cycloneiii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLK~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK~inputclkctrl_outclk\);

-- Location: IOIBUF_X0_Y5_N8
\S0~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_S0,
	o => \S0~input_o\);

-- Location: IOIBUF_X0_Y6_N15
\S1~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_S1,
	o => \S1~input_o\);

-- Location: LCCOMB_X1_Y5_N6
\inst|41~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|41~0_combout\ = (!\S0~input_o\ & ((\S1~input_o\ & ((\inst|40~q\))) # (!\S1~input_o\ & (\inst|41~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \S1~input_o\,
	datac => \inst|41~q\,
	datad => \inst|40~q\,
	combout => \inst|41~0_combout\);

-- Location: IOIBUF_X0_Y14_N8
\CLRN~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLRN,
	o => \CLRN~input_o\);

-- Location: CLKCTRL_G2
\CLRN~inputclkctrl\ : cycloneiii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLRN~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLRN~inputclkctrl_outclk\);

-- Location: FF_X1_Y5_N7
\inst|41\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \inst|41~0_combout\,
	clrn => \CLRN~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|41~q\);

-- Location: LCCOMB_X1_Y5_N10
\inst|36~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|36~0_combout\ = (\S0~input_o\ & ((\S1~input_o\) # ((\inst|41~q\)))) # (!\S0~input_o\ & (\S1~input_o\ & (\inst|39~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101011001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \S1~input_o\,
	datac => \inst|39~q\,
	datad => \inst|41~q\,
	combout => \inst|36~0_combout\);

-- Location: LCCOMB_X1_Y5_N4
\inst|36~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|36~1_combout\ = (\inst|36~0_combout\) # ((!\S0~input_o\ & (!\S1~input_o\ & \inst|40~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \S1~input_o\,
	datac => \inst|40~q\,
	datad => \inst|36~0_combout\,
	combout => \inst|36~1_combout\);

-- Location: FF_X1_Y5_N5
\inst|40\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \inst|36~1_combout\,
	clrn => \CLRN~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|40~q\);

-- Location: LCCOMB_X1_Y5_N20
\inst|35~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|35~0_combout\ = (!\S1~input_o\ & ((\S0~input_o\ & (\inst|40~q\)) # (!\S0~input_o\ & ((\inst|39~q\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000100100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \S1~input_o\,
	datac => \inst|40~q\,
	datad => \inst|39~q\,
	combout => \inst|35~0_combout\);

-- Location: LCCOMB_X1_Y5_N30
\inst|35~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|35~1_combout\ = (\inst|35~0_combout\) # ((!\S0~input_o\ & (\inst|38~q\ & \S1~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \inst|38~q\,
	datac => \S1~input_o\,
	datad => \inst|35~0_combout\,
	combout => \inst|35~1_combout\);

-- Location: FF_X1_Y5_N31
\inst|39\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \inst|35~1_combout\,
	clrn => \CLRN~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|39~q\);

-- Location: LCCOMB_X1_Y5_N24
\inst|34~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst|34~0_combout\ = (\S0~input_o\ & ((\S1~input_o\) # ((\inst|39~q\)))) # (!\S0~input_o\ & (!\S1~input_o\ & (\inst|38~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101010011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \S0~input_o\,
	datab => \S1~input_o\,
	datac => \inst|38~q\,
	datad => \inst|39~q\,
	combout => \inst|34~0_combout\);

-- Location: FF_X1_Y5_N25
\inst|38\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK~inputclkctrl_outclk\,
	d => \inst|34~0_combout\,
	clrn => \CLRN~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst|38~q\);

ww_Q(3) <= \Q[3]~output_o\;

ww_Q(2) <= \Q[2]~output_o\;

ww_Q(1) <= \Q[1]~output_o\;

ww_Q(0) <= \Q[0]~output_o\;
END structure;


