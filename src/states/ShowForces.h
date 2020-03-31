#pragma once

#include <mc_control/fsm/State.h>

namespace mc_rbdyn
{
  struct Robot;
  struct ForceSensor;
} /* mc_rbdyn */

namespace mc_rtc
{
namespace gui
{
  struct StateBuilder;
} /* gui */
} /* mc_rtc */

namespace mc_control
{
  namespace fsm
  {
    struct Controller;
  } /* fsm */
} /* mc_control */

struct ShowForces : mc_control::fsm::State
{

    void configure(const mc_rtc::Configuration & config) override;

    void start(mc_control::fsm::Controller & ctl) override;

    bool run(mc_control::fsm::Controller & ctl) override;

    void teardown(mc_control::fsm::Controller & ctl) override;

    void saveCalibration(mc_control::fsm::Controller & ctl);

    void addWrenchPlot(const std::string & name, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::ForceSensor & fs);
    void addWrenchWithoutGravityPlot(const std::string & name, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::Robot & robot, const mc_rbdyn::ForceSensor & fs);
    void addWrenchWithoutGravityPlot(const std::string & name, const std::string & surface, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::Robot & robot, const mc_rbdyn::ForceSensor & fs);

    void addWrenchVector(const std::string & name, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::Robot & robot, const mc_rbdyn::ForceSensor & fs);
    void addWrenchWithoutGravityVector(const std::string & name, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::Robot & robot, const mc_rbdyn::ForceSensor & fs);
    void addWrenchWithoutGravityVector(const std::string & name, const std::string & surface, mc_rtc::gui::StateBuilder & gui, const mc_rbdyn::Robot & robot, const mc_rbdyn::ForceSensor & fs);
 private:
    double t_ = 0;
    std::vector<std::pair<std::string, std::string>> sensors_;
    bool running_ = true;

    std::vector<std::string> category_;
    std::vector<std::string> plots_;
    // Map of force sensor to surface name (chosen in the gui)
    std::map<std::string, std::string> surfaces_;
};
