//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "InputAxisSettings.h"


namespace Interop { namespace Input {

/// <summary>
///  <para>Provides read-only information about one axis input belonging to an input device.</para>
///  <para>Instances of this class are immutable.</para>
/// </summary>
class InputAxisInfo
{
	public:
		#pragma region Constructors/Destructors
		/// <summary>Creates an immutable object providing a copy of the given axis information.</summary>
		/// <param name="settings">The axis settings to be copied.</param>
		InputAxisInfo(const InputAxisSettings& settings);

		/// <summary>Destroys this object.</summary>
		virtual ~InputAxisInfo();

		#pragma endregion


		#pragma region Public Methods
		/// <summary>Gets the type of axis such as kX, kY, kLeftTrigger, kRightTrigger, etc.</summary>
		/// <returns>Returns the type of axis input this is.</returns>
		Rtt::InputAxisType GetType() const;

		/// <summary>Gets the minimum value that this axis input can provide.</summary>
		/// <returns>Returns the minimum value that can be provided.</returns>
		int32_t GetMinValue() const;

		/// <summary>Gets the maximum value that this axis input can provide.</summary>
		/// <returns>Returns the maximum value that can be provided.</returns>
		int32_t GetMaxValue() const;

		/// <summary>Gets the +/- accuracy of the values this axis input provides.</summary>
		/// <returns>
		///  <para>Returns the accuracy of this axis input's values. Will be greater than or equal to zero.</para>
		///  <para>
		///   A value of zero indicates perfect accuracy, but more likely indicates that the accuracy
		///   of the input device is unknown.
		///  </para>
		/// </returns>
		float GetAccuracy() const;

		/// <summary>Determines if this axis input provides absolute values or relative values.</summary>
		/// <returns>
		///  <para>
		///   Returns true if the axis provides absolute values, meaning that it is positional data.
		///   This is typically used by joysticks, indicating their currently held position.
		///  </para>
		///  <para>
		///   Returns false if the axis provides relative values, which is typically the distance travelled
		///   since the last axis input event. This is typically used by mice and trackpads, indicating
		///   how far the input device has moved since it's last input event.
		///  </para>
		/// </returns>
		bool IsAbsolute() const;

		/// <summary>Determines if this axis configuration matches the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations match. Returns false if not.</returns>
		bool Equals(const InputAxisInfo& value) const;

		/// <summary>Determines if this axis configuration matches the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations match. Returns false if not.</returns>
		bool Equals(const InputAxisSettings& value) const;

		/// <summary>Determines if this axis configuration does not match the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations do not match. Returns false if they do match.</returns>
		bool NotEquals(const InputAxisInfo& value) const;

		/// <summary>Determines if this axis configuration does not match the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations do not match. Returns false if they do match.</returns>
		bool NotEquals(const InputAxisSettings& value) const;

		/// <summary>Determines if this axis configuration matches the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations match. Returns false if not.</returns>
		bool operator==(const InputAxisInfo& value) const;

		/// <summary>Determines if this axis configuration matches the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations match. Returns false if not.</returns>
		bool operator==(const InputAxisSettings& value) const;

		/// <summary>Determines if this axis configuration does not match the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations do not match. Returns false if they do match.</returns>
		bool operator!=(const InputAxisInfo& value) const;

		/// <summary>Determines if this axis configuration does not match the given axis configuration.</summary>
		/// <param name="value">Reference to the axis configuration to compare against.</param>
		/// <returns>Returns true if the axis configurations do not match. Returns false if they do match.</returns>
		bool operator!=(const InputAxisSettings& value) const;

		#pragma endregion

	private:
		#pragma region Private Methods
		/// <summary>Assignment operator made private to make this object immutable.</summary>
		void operator=(const InputAxisInfo& info) {}

		#pragma endregion


		#pragma region Private Member Variables
		/// <summary>A copy of the axis settings wrapped by this immutable object.</summary>
		InputAxisSettings fSettings;

		#pragma endregion
};

} }	// namespace Interop::Input
